"""
INSERT MANY RECORDS
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
    val = [
        ('Peter', '6', '8'),
        ('Amy', '6', '10'),
        ('Hannah', '7', '8'),
        ('Michael', '7', '10'),
        ('Sandy', '6', '9'),
        ('Betty', '7', '6'),
        ('Richard', '7', '5'),
        ('Susan', '6', '9'),
        ('Vicky', '6', '10'),
        ('Ben', '7', '8'),
        ('William', '6', '9'),
        ('Chuck', '6', '10'),
        ('Viola', '7', '10')
    ]

    my_cursor.executemany(sql, val)

    mydb.commit()

    print(my_cursor.rowcount, "was inserted.")

except mysql.connector.Error as e:
    print(e)
