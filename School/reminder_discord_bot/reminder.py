#Copyright by khivus (Aleksey Kharin) 2021
import discord
import config
from time import gmtime, strftime, localtime
import datamanager
import threading

client = discord.Client()

#strftime("%Y-%m-%d %H:%M:%S", gmtime())

mess = []
prefix = "r!"
cmdHelp = "help"
cmdStop = "stop"
whatstime = 'time'
autosend = 'add_conf'
remove_config = 'remove_conf'
data = 'data'
remove_all = 'data_clear'

i=1 # i as interval in seconds
def looper():
    threading.Timer(i, looper).start()
    if datamanager.get_messages_by_time(strftime("%H:%M:%S", localtime())) != None:
        content = datamanager.get_messages_by_time(strftime("%H:%M:%S", localtime()))
        channel_id = content[0]
        time_message = content[2]
        content_message = content[3]
        print( 'bot sent', content_message, 'in', channel_id )
        return content

@client.event
async def on_ready():
    print('We have logged in as {0.user}'.format(client))
    activity = discord.Activity(name=' ur browsing history ', type=discord.ActivityType.watching)
    await client.change_presence(activity=activity)
@client.event
async def on_disconnect():
    print("Client have successfully closed")

@client.event
async def on_message(message):
    if message.author == client.user:
        return

    if message.content.startswith(prefix):
        msg = message.content.removeprefix(prefix)

        if msg == cmdHelp:
            embed=discord.Embed(title="There is a list of commands", description="be sure you use prefix(r!)", color=0xba3ad4)
            embed.add_field(name="1. help", value="for commands", inline=True)
            embed.add_field(name="2. stop", value="bot will shut down", inline=True)
            embed.add_field(name="3. time", value="time now (GMT+3 only)", inline=True)
            embed.add_field(name="4. data", value="will send all data in console", inline=True)
            embed.add_field(name="5. add_conf { HH:MM:SS 'Message that need to be posted' }", value="Configurate time and context of message what you need to send every N time (GMT+3 only) (not working for now)", inline=True)
            embed.add_field(name="6. remove_conf { HH:MM:SS 'Message that you had wrote' }", value="This command will disable autoreminds from bot", inline=True)
            embed.add_field(name="7. data_clear", value="remove all data", inline=True)
            await message.channel.send (embed=embed)

        if msg == cmdStop:
            await message.channel.send("Aight, going to sleep while I can")
            await client.close()

        if msg.startswith(autosend):
            await message.channel.send('I got it!')
            mess = [message.channel.id, message.id, msg[9:17], msg[18::]]
            print(mess)
            datamanager.insert_data(mess)

        if msg == whatstime:
            await message.channel.send(strftime("%H:%M:%S(GMT+3)", localtime()))

        if msg == data:
            datamanager.get_data()

        if msg.startswith(remove_config):
            await message.channel.send("Config removed.")
            conf = [msg[12:20], msg[21::]]
            datamanager.remove_config(conf)

        if msg == remove_all:
            datamanager.remove_all()

        if msg == 'start':
            print('B A B A B O O E')
            content = looper()
            if content != None:
                print('sus')

client.run(config.token)