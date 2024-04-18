import mysql.connector

try:
    mydb = mysql.connector.connect(
        host="localhost",
        user="root",
        password="1234",
        database="iot"
    )

    my_cursor = mydb.cursor()

    sql = "SELECT * FROM alumnos ORDER BY nombre"
    #  sql = "SELECT * FROM customers ORDER BY username DESC"
    my_cursor.execute(sql)

    my_result = my_cursor.fetchall()

    for x in my_result:
        print(x)

except mysql.connector.Error as e:
    print(e)
