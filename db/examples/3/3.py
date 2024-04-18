"""
CONNECT TO DB
"""

import mysql.connector

try:
    mydb = mysql.connector.connect(
        host="localhost",
        user="root",
        password="1234",
        database="iot"
    )

    print('You are connected')

except mysql.connector.Error as e:
    print(e)
