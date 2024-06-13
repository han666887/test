
# -*- coding: gbk -*-
#from fileinput import filelineno
import camelot
from openpyxl import Workbook
import pandas as pd
import os
import sys

# 获取当前执行的exe或脚本的完整路径
current_exe_path = os.path.abspath(sys.argv[0])
# 获取当前脚本所在的目录
current_directory = os.path.dirname(current_exe_path)

pdf_path = current_directory  + "\\1.pdf"
print(pdf_path)


#work = Workbook()
#sheet = work.active


## PDF文件路径
#pdf_path = 'C:\\Users\\hqk\\Desktop\\pdftoexcel\\1.pdf'


# 读取PDF文件中的所有表格
tables = camelot.read_pdf(pdf_path, pages='all', flavor='stream')


# 检查解析出的表格数量
print(f"Found {len(tables)} tables in the PDF file.")

# 创建一个 Excel writer 对象
with pd.ExcelWriter('success.xlsx', engine='openpyxl') as excel_writer:
    # 将每个表格保存到一个单独的 Excel sheet 中
    for i, table in enumerate(tables):
        # 获取表格数据并转换为 DataFrame
        df = table.df

        # 将 DataFrame 写入 Excel sheet，sheet 名称为 'Sheet1', 'Sheet2', ...
        df.to_excel(excel_writer, sheet_name=f'Sheet{i+1}', index=False)

print("Tables have been successfully saved to 'success.xlsx'.")


#for i in range(tables.n):
#    for rows in tables[i].data:
#        sheet.append(rows)
#work.save('success.xlsx')

