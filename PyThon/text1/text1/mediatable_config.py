#!/usr/bin/env python
#coding=utf-8

import re
import sys,os
import csv
import inspect
import xlrd

tables = [
	("table", str),						# テーブル
	("am_freq", str),					# AM:AM周波数 [kHz]
	("am_freq_step", str),				# AM:周波数ステップ [kHz]
	("am_initial_channel",str),			# AM:初期プリセットチャネル 周波数 [kHz]
	("am_traffic_info", bool),			# AM:放送局名表示/交通情報
	("fm_freq", str),					# FM:FM周波数 [kHz]
	("fm_freq_step", str),				# FM:周波数ステップ [kHz]
	("fm_initial_channel",str),			# FM:初期プリセットチャネル 周波数 [MHz]
	("fm_traffic_info", bool),			# FM:放送局名表示/VICS-FM
	("dab_band3_range", str),			# DAB:DAB BandIII 周波数範囲
	("dab_band3_block_label", str),		# DAB:Band III Block Label
	("dab_fm_link", bool),				# DAB:DAB-FMリンク
	("rds_ps", bool),					# RDS:PS
	("rds_af", bool),					# RDS:AF
	("rds_ta", bool),					# RDS:TA
	("rds_pty", bool),					# RDS:PTY
	("rds_pty31", bool),				# RDS:PTY31（ALARM）
	("rds_reg", bool),					# RDS:REG
	("rds_eon", bool),					# RDS:EON
	("rds_rt", bool),					# RDS:RT
	("rds_station_list", bool),			# RDS:ステーションリスト
	("drm", bool),						# DRM
	("tv", bool),						# TV(NAVI_BOX)
	("hdmi", bool),						# HDMI(NAVI_BOX)
	("wifi_freq", str),					# Wifi周波数[GHz]
	("cp_usb", bool),					# Apple Carplay:USB接続
	("cp_wifi", bool),					# Apple Carplay:Wi-Fi接続
	("aa_usb", bool),					# Android Auto:USB接続
	("aa_wifi", bool),					# Android Auto:Wi-Fi接続
	("aa_ev_connector_type", str),		# Android Auto:充電コネクタタイプ(Android Auto用)
	("navicon", bool),					# Navicon
	("tm_switch_auto", bool),			# 時計,タイムゾーン / サマータイム切り替え:オート
	("tm_swtich_manual", bool),			# 時計,タイムゾーン / サマータイム切り替え:マニュアル
	("video_reg", bool),				# 動画規制
	("sound_quality", str),				# 音質/音量特性 
]

def getpath():
	this_file = inspect.getfile(inspect.currentframe())
	path = os.path.abspath(os.path.dirname(this_file))
	return path

def parse_string(table, row, index):
	value = table.cell(row, index + 1).value
	if (isinstance(value, float)):
		if not value - int(value):
			value = int(value)
	elif str(value) == '-':
		value = 'Disable'
	key_value = tables[index][0] + " = " + str(value) + "\n"
	return key_value

def parse_bool(table, row, index):
	value = table.cell(row, index + 1).value
	if str(value) == '○' or str(value) == '〇':
		value = 'Enable'
	elif str(value) == '-':
		value = 'Disable'
	key_value = tables[index][0] + " = " + str(value) + "\n"
	return key_value

def parse_cell(table, row, index):
	key_value = ""
	if tables[index][1] == str:
		key_value =  parse_string(table, row, index)
	elif tables[index][1] == bool:
		key_value =  parse_bool(table, row, index)
	return key_value

if __name__ == '__main__':
	#if len(sys.argv) != 2:
	if len(sys.argv) == 2 and sys.argv[1] == '?':
		print('>mediatable_config.py')
		print('note: need install xlrd')
		print('      uri - http://pypi.python.org/pypi/xlrd')
		print('      install - setup.py install')

		exit()
	print('start generate')

	xls_path = 'D:\\vs2022\\PyThon\\text1\\text1\\IDS_Variant_table_Ver_1.3.0.1.xls'

	file_dict = {"メディアテーブル":\
				["mediatable_config"]}

	data = xlrd.open_workbook(xls_path)

	for (key,xitem) in file_dict.items():

		table = data.sheet_by_name(key)
		nrows = table.nrows

		for file_item in xitem:
			print('generate ' + file_item)
			f = open(file_item,"w")
			f.write("[MediaTable]")
			f.write("\n")
			f.write("<note: All value's type is string.>")
			f.write("\n")
			f.write("\n")
			for i in range(8, nrows):

				# Section
				key = table.cell(i, 1).value
				key_s = "[" + key + "]" + "\n"
				f.write(key_s)

				j = 0
				while j < len(tables):
					f.write(parse_cell(table, i, j))
					j += 1

				f.write("\n")
			f.close()
	print('finished')
