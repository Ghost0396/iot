import mysql.connector

try:
    mydb = mysql.connector.connect(
        host="localhost",
        user="root",
        password="1234"
        )

    cursor = mydb.cursor()

    cursor.execute("CREATE DATABASE iot")

    print("DB CREATED")

except mysql.connector.Error as e:
    print(e)
