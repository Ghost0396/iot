"""
CREATE TABLE
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
    my_cursor.execute("CREATE TABLE alumnos (nombre VARCHAR(255), clase VARCHAR(255), calificacion VARCHAR(255))")  # noqa: E501

except mysql.connector.Error as e:
    print(e)
