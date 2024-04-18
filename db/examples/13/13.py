"""

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

    sql = "SELECT * FROM alumnos WHERE nombre LIKE '%y'"

    my_cursor.execute(sql)

    my_result = my_cursor.fetchall()

    for result in my_result:
        print(result)

except mysql.connector.Error as e:
    print(e)
