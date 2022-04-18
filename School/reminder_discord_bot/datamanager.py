import sqlite3

conn = sqlite3.connect( 'database.bd', check_same_thread=False )
cur = conn.cursor()

try:
    cur.execute( ''' CREATE TABLE Messages (
                    channel integer,
                    message integer,
                    time text,
                    content text
                    ) ''' )
except sqlite3.OperationalError:
    print('Table "Messages" already created')

def insert_data(mess):
    mess1 = mess[0]
    mess2 = mess[1]
    mess3 = mess[2]
    mess4 = mess[3]
    with conn:
        cur.execute(' INSERT INTO Messages VALUES (:channel, :message, :time, :content) ', {'channel': mess1, 'message' :mess2, 'time': mess3, 'content': mess4} )
        print('data had successfully saved')

def get_messages_by_time(time1):
    cur.execute('SELECT * FROM Messages WHERE time = :time', { 'time': time1 } )
    mess = cur.fetchone()
    return mess

def get_data():
    cur.execute(' SELECT * FROM Messages ')
    print(cur.fetchall())

def remove_config(conf):
    conf_t = conf[0]
    conf_c = conf[1]
    with conn:
        cur.execute( ' DELETE from Messages WHERE time = :time and content = :content', { 'time' :conf_t, 'content' :conf_c } )
        print(conf, 'had successfully removed')

def remove_all():
    with conn:
        cur.execute( ' DELETE FROM Messages ' )
        print('all data has removed')

conn.close