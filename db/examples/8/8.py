"""
INSERT RECORD
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

    sql = "INSERT INTO alumnos (nombre, clase, calificacion) VALUES (%s, %s, %s)"  # noqa: E501
    val = ("pedro", "7", "70")
    my_cursor.execute(sql, val)

    mydb.commit()

    print(my_cursor.rowcount, "record inserted.")

except mysql.connector.Error as e:
    print(e)
