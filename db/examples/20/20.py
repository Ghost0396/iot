import mysql.connector
from mysql.connector import Error


def delete_database(db_name):
    try:
        connection = mysql.connector.connect(
            host='localhost',
            user='root',
            password='1234'
        )

        cursor = connection.cursor()

        delete_query = f"DROP DATABASE {db_name};"

        cursor.execute(delete_query)

        connection.commit()
        print(f"Database {db_name} deleted successfully.")

    except Error as e:
        print(f"Error: {e}")

    finally:
        if connection.is_connected():
            cursor.close()
            connection.close()
            print("MySQL connection is closed")


delete_database('iot')
