# -*- coding: gbk -*-
import camelot
import sys
from openpyxl import Workbook
import os

# 获取当前执行的exe或脚本的完整路径
current_exe_path = os.path.abspath(sys.argv[0])
# 获取当前脚本所在的目录
current_directory = os.path.dirname(current_exe_path)

pdf_path = current_directory  + "\\1.pdf"
print(pdf_path)


work = Workbook()
sheet = work.active
 
# 从键盘输入需要解析的PDF页码
pdf_page_number = input("请输入需要解析的PDF页码(从1开始)：")

filename = f"page_{pdf_page_number}.xlsx"
# 确保页码是数字
try:
    page_number = int(pdf_page_number)
except ValueError:
    print("页码必须是数字！")
    sys.exit(1)
 
# 加载PDF文件
tables = camelot.read_pdf(pdf_path, pages=pdf_page_number, flavor='stream',edge_tol=200,strip_text="\n")


for i in range(tables.n):
    for rows in tables[i].data:
        sheet.append(rows)
work.save(filename)

