"""
SELECT
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

    my_cursor.execute("SELECT nombre, clase FROM alumnos")

    my_result = my_cursor.fetchall()

    for row in my_result:
        print(row)

except mysql.connector.Error as e:
    print(e)
