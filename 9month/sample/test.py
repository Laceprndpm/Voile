from selenium import webdriver
from selenium.webdriver.common.by import By
import time
from PIL import Image
import pytesseract

#初始化浏览器
driver = webdriver.Edge()
driver.get('http://my.nau.edu.cn')
time.sleep(1)
driver.maximize_window()
time.sleep(1)
#获取验证码
code_location=driver.find_element(By.CLASS_NAME,'codeImg')
driver.save_screenshot('.\\code1.png')
location=code_location.location
size=code_location.size
left=location['x']
top=location['y']
right=left+size['width']
bottom=top+size['height']
img=Image.open('.\\code1.png')
frame=img.crop((left,top,right,bottom))
# frame.show()
frame.save('.\\code.png')
path='code.png'
code_img=Image.open(path)
code=pytesseract.image_to_string(code_img)
#输入信息并登录
driver.find_element(By.ID,'username').send_keys('学号')
driver.find_element(By.ID,'password').send_keys('密码')
driver.find_element(By.ID,'authcode').send_keys(code)
time.sleep(1)
#教务在线
driver.find_element(By.XPATH,'/html/body/div/div[3]/div/div/div[1]/div[1]/div/div/div/div/div/div/div[2]/div/ul/li[1]/p').click()
time.sleep(1)
#当前页面操作
driver.switch_to.window(driver.window_handles[1])
driver.find_element(By.XPATH,'/html/body/div[8]/div[1]/div[3]/a').click()
#在线选课
driver.find_element(By.XPATH,'//*[@id="tt_easyui_tree_23"]/span[3]').click()
#通识教育任选课
driver.find_element(By.XPATH,'//*[@id="tt_easyui_tree_40"]/span[4]/a').click()
# 英语后续课程
# driver.find_element(By.XPATH,'//*[@id="tt_easyui_tree_43"]/span[4]/a').click()
# time.sleep(1)
#跳转到选课iframe界面
iframe=driver.find_element(By.XPATH,'//*[@id="FrameContent"]')
driver.switch_to.frame(iframe)
#课程序号
driver.find_element(By.XPATH,'//*[@id="CourseList"]/tbody/tr[200]/td[1]/input').click()
#确认选课信息
driver.find_element(By.XPATH,'//*[@id="SubmitBtn1"]/a/span/span[1]').click()