import mysql.connector

try:
    mydb = mysql.connector.connect(
        host="localhost",
        user="root",
        password="1234",
        database="iot"
    )

    my_cursor = mydb.cursor()

    sql = "DELETE FROM alumnos WHERE calificacion = %s"
    adr = ("8",)

    my_cursor.execute(sql, adr)

    mydb.commit()

    print(my_cursor.rowcount, "record(s) deleted")

except mysql.connector.Error as e:
    print(e)
