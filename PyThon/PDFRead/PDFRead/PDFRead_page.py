# -*- coding: gbk -*-
import camelot
import sys
from openpyxl import Workbook
import os

# ��ȡ��ǰִ�е�exe��ű�������·��
current_exe_path = os.path.abspath(sys.argv[0])
# ��ȡ��ǰ�ű����ڵ�Ŀ¼
current_directory = os.path.dirname(current_exe_path)

pdf_path = current_directory  + "\\1.pdf"
print(pdf_path)


work = Workbook()
sheet = work.active
 
# �Ӽ���������Ҫ������PDFҳ��
pdf_page_number = input("��������Ҫ������PDFҳ��(��1��ʼ)��")

filename = f"page_{pdf_page_number}.xlsx"
# ȷ��ҳ��������
try:
    page_number = int(pdf_page_number)
except ValueError:
    print("ҳ����������֣�")
    sys.exit(1)
 
# ����PDF�ļ�
tables = camelot.read_pdf(pdf_path, pages=pdf_page_number, flavor='stream',edge_tol=200,strip_text="\n")


for i in range(tables.n):
    for rows in tables[i].data:
        sheet.append(rows)
work.save(filename)

