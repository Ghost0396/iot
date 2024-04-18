import mysql.connector

try:
    mydb = mysql.connector.connect(
        host="localhost",
        user="root",
        password="1234",
        database="iot"
    )

    my_cursor = mydb.cursor()

    sql = "UPDATE alumnos SET calificacion = '9' WHERE nombre = 'Amy'"

    my_cursor.execute(sql)

    mydb.commit()

    print(my_cursor.rowcount, "record(s) affected")

except mysql.connector.Error as e:
    print(e)
