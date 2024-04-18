import mysql.connector

try:
    mydb = mysql.connector.connect(
        host="localhost",
        user="root",
        password="1234",
        database="iot"
    )

    my_cursor = mydb.cursor()

    sql = "DROP TABLE IF EXISTS alumnos"

    my_cursor.execute(sql)

except mysql.connector.Error as e:
    print(e)
