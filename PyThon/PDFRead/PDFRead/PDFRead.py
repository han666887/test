
# -*- coding: gbk -*-
#from fileinput import filelineno
import camelot
from openpyxl import Workbook
import pandas as pd
import os
import sys

# ��ȡ��ǰִ�е�exe��ű�������·��
current_exe_path = os.path.abspath(sys.argv[0])
# ��ȡ��ǰ�ű����ڵ�Ŀ¼
current_directory = os.path.dirname(current_exe_path)

pdf_path = current_directory  + "\\1.pdf"
print(pdf_path)


#work = Workbook()
#sheet = work.active


## PDF�ļ�·��
#pdf_path = 'C:\\Users\\hqk\\Desktop\\pdftoexcel\\1.pdf'


# ��ȡPDF�ļ��е����б��
tables = camelot.read_pdf(pdf_path, pages='all', flavor='stream')


# ���������ı������
print(f"Found {len(tables)} tables in the PDF file.")

# ����һ�� Excel writer ����
with pd.ExcelWriter('success.xlsx', engine='openpyxl') as excel_writer:
    # ��ÿ����񱣴浽һ�������� Excel sheet ��
    for i, table in enumerate(tables):
        # ��ȡ������ݲ�ת��Ϊ DataFrame
        df = table.df

        # �� DataFrame д�� Excel sheet��sheet ����Ϊ 'Sheet1', 'Sheet2', ...
        df.to_excel(excel_writer, sheet_name=f'Sheet{i+1}', index=False)

print("Tables have been successfully saved to 'success.xlsx'.")


#for i in range(tables.n):
#    for rows in tables[i].data:
#        sheet.append(rows)
#work.save('success.xlsx')

