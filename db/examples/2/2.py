"""
SHOW DATABASES
"""

import mysql.connector

try:
    mydb = mysql.connector.connect(
        host="localhost",
        user="root",
        password="1234"
    )

    cursor = mydb.cursor()
    cursor.execute("SHOW DATABASES")

    for db in cursor:
        print(db)

except mysql.connector.Error as e:
    print(e)
