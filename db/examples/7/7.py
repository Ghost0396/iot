"""
ADD PRIMARY KEY
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

    my_cursor.execute("ALTER TABLE alumnos ADD COLUMN id INT AUTO_INCREMENT PRIMARY KEY")  # noqa: E501

except mysql.connector.Error as e:
    print(e)
