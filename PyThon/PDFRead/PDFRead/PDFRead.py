
# -*- coding: gbk -*-
import camelot
import pandas as pd
from openpyxl import Workbook





work = Workbook()
sheet = work.active


# PDF文件路径
pdf_path = 'C:\\Users\\EDY\\Desktop\\pdftoexcel\\1.pdf'

# 读取PDF文件中的所有表格
tables = camelot.read_pdf(pdf_path, pages='all', flavor='stream')

for i in range(tables.n):
    for rows in tables[i].data:
        sheet.append(rows)
work.save('success.xlsx')

## 创建一个 Excel 写入器
#with pd.ExcelWriter('output.xlsx') as writer:
#    # 遍历所有提取的表格
#    for i, table in enumerate(tables):
#        # 将表格数据转换为 pandas DataFrame
#        df = table.df
        
#        # 将 DataFrame 写入 Excel 文件的不同工作表中
#        df.to_excel(writer, sheet_name=f'Sheet{i+1}', index=False)


print("PDF")



## 遍历提取的表格列表
#for i, table in enumerate(tables):
#    # 将表格数据转换为pandas DataFrame
#    df = table.df
    
#    # 显示或处理DataFrame
#    print(f"Table {i+1}:")
#    print(df)
#    print("\n")
    
    # 如果需要，可以将DataFrame保存为CSV文件
    # df.to_csv(f'table_{i+1}.csv', index=False, encoding='utf-8-sig')

# 如果你只想提取特定页面的表格，你可以指定页码
# 例如，提取第一页的表格
# first_page_tables = camelot.read_pdf(pdf_path, pages='1')
# for table in first_page_tables:
#    df = table.df
#    print(df)