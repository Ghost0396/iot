"""
CREATE TABLE WITH PRIMARY KEY
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

    my_cursor.execute(
        "CREATE TABLE alumnosid (id INT AUTO_INCREMENT PRIMARY KEY, name VARCHAR(255), address VARCHAR(255))")  # noqa: E501
except mysql.connector.Error as e:
    print(e)
