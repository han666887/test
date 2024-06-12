
# -*- coding: utf-8 -*-
import camelot
import pandas as pd

# PDF�ļ�·��
pdf_path = 'D:\\vs2022\\PyThon\\PDFRead\\PDFRead\\2.pdf'

# ��ȡPDF�ļ��е����б���
tables = camelot.read_pdf(pdf_path, pages='all', flavor='stream')


# ����һ�� Excel д����
with pd.ExcelWriter('output.xlsx') as writer:
    # ����������ȡ�ı���
    for i, table in enumerate(tables):
        # ����������ת��Ϊ pandas DataFrame
        df = table.df
        
        # �� DataFrame д�� Excel �ļ��Ĳ�ͬ��������
        df.to_excel(writer, sheet_name=f'Sheet{i+1}', index=False)

print("PDF")



# ������ȡ�ı����б�
#for i, table in enumerate(tables):
    # ����������ת��Ϊpandas DataFrame
  #  df = table.df
    
    # ��ʾ����DataFrame
 #   print(f"Table {i+1}:")
 #   print(df)
 #   print("\n")
    
    # �����Ҫ�����Խ�DataFrame����ΪCSV�ļ�
    # df.to_csv(f'table_{i+1}.csv', index=False, encoding='utf-8-sig')

# �����ֻ����ȡ�ض�ҳ��ı��������ָ��ҳ��
# ���磬��ȡ��һҳ�ı���
# first_page_tables = camelot.read_pdf(pdf_path, pages='1')
# for table in first_page_tables:
#    df = table.df
#    print(df)