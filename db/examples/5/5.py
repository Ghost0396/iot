"""
SHOW TABLES
"""
import mysql.connector

try:
    mydb = mysql.connector.connect(
        host="localhost",
        user="root",
        password="1234",
        database="iot"
    )

    my_cursor = mydb.cursor()
    my_cursor.execute("SHOW TABLES")

    for table in my_cursor:
        print(table)

except mysql.connector.Error as e:
    print(e)
