import smtplib
from email.MIMEMultipart import MIMEMultipart
from email.MIMEText import MIMEText
from email.MIMEBase import MIMEBase
from email import encoders
 
fromaddr = "hez864@newschool.edu"
toaddr = "hez864@newschool.edu"
 
msg = MIMEMultipart()
 
msg['From'] = fromaddr
msg['To'] = toaddr
msg['Subject'] = "YourLoveGran"
 
body = ""
 
msg.attach(MIMEText(body, 'plain'))
 
filename = "1.jpg"
attachment = open("/Users/heziqiang/1/public/images/1.jpg", "rb")
 
part = MIMEBase('application', 'octet-stream')
part.set_payload((attachment).read())
encoders.encode_base64(part)
part.add_header('Content-Disposition', "attachment; filename= %s" % filename)
 
msg.attach(part)
 
server = smtplib.SMTP('smtp.gmail.com', 587)
server.starttls()
server.login(fromaddr, "Gomat110!")
text = msg.as_string()
server.sendmail(fromaddr, toaddr, text)
server.quit()