import sensor, image, time,machine,array,lcd
from machine import UART
from fpioa_manager import fm
from board import board_info

fm.register(board_info.PIN15, fm.fpioa.UART1_TX)
fm.register(board_info.PIN17, fm.fpioa.UART1_RX)

myUART = UART(UART.UART1, 115200,8,0,0, timeout=1000, read_buf_len=4096)

lcd.init(freq=15000000)
sensor.reset()
sensor.set_pixformat(sensor.RGB565)
sensor.set_framesize(sensor.QVGA)
sensor.skip_frames(time = 2000)
clock = time.clock()

ball_threshold = (23, 40, 27, 54, 56, 13)
blueGoal_threshold = (28, 13, 23, -8, -55, -24)
YellowGoal_threshold = (75, 27, -28, 0, 52, 24)


header = 128 #ヘッダー
ballX = 0
ballY = 0
blueGoalX = 0
blueGoalY = 0
yellowGoalX = 0
yellowGoalY = 0
imgCentorX = 154 #ミラーの中心のX座標
imgCentorY = 115 #ミラーの中心のy座標

while(True):
    clock.tick()
    img = sensor.snapshot()

    preBallArea = 0
    preBlueGoalArea = 0
    preYellowGoalArea = 0

    for ball in img.find_blobs([ball_threshold]):
        if ball.area() > preBallArea:
            ballX = ball.cx()
            ballY = ball.cy()
            preBallArea = ball.area()

    #img.draw_rectangle(ball.rect())
    img.draw_cross(ballX, ballY)
    img.draw_line(imgCentorX, imgCentorY, ballX, ballY, 210, thickness=2)

    for blueGoal in img.find_blobs([blueGoal_threshold]):
        if blueGoal.area() > preBlueGoalArea:
            blueGoalX = blueGoal.cx()
            blueGoalY = blueGoal.cy()
            preBlueGoalArea = blueGoal.area()

    #img.draw_rectangle(blueGoal.rect())
    img.draw_cross(blueGoalX, blueGoalY)
    img.draw_line(imgCentorX, imgCentorY, blueGoalX, blueGoalY,200 , thickness=2)

    for yellowGoal in img.find_blobs([YellowGoal_threshold]):
        if yellowGoal.area() > preYellowGoalArea:
            yellowGoalX = yellowGoal.cx()
            yellowGoalY = yellowGoal.cy()
            preYellowGoalArea = yellowGoal.area()

    #img.draw_rectangle(yellowGoal.rect())
    img.draw_cross(yellowGoalX, yellowGoalY)
    img.draw_line(imgCentorX, imgCentorY, yellowGoalX, yellowGoalY,255, thickness=2)

    high_ballX = (ballX >> 7) & 127
    low_ballX = ballX & 127
    high_ballY = (ballY >> 7) & 127
    low_ballY = ballY & 127

    high_blueGoalX = (blueGoalX >> 7) & 127
    low_blueGoalX = blueGoalX & 127
    high_blueGoalY = (blueGoalY >> 7) & 127
    low_blueGoalY = blueGoalY & 127

    high_yellowGoalX = (yellowGoalX >> 7) & 127
    low_yellowGoalX = yellowGoalX & 127
    high_yellowGoalY = (yellowGoalY >> 7) & 127
    low_yellowGoalY = yellowGoalY & 127

    headerByte = header.to_bytes(1,'big')

    highByte_ballX = high_ballX.to_bytes(1,'big')
    lowByte_ballX = low_ballX.to_bytes(1,'big')
    highByte_ballY = high_ballY.to_bytes(1,'big')
    lowByte_ballY = low_ballY.to_bytes(1,'big')

    highByte_blueGoalX = high_blueGoalX.to_bytes(1,'big')
    lowByte_blueGoalX = low_blueGoalX.to_bytes(1,'big')
    highByte_blueGoalY = high_blueGoalY.to_bytes(1,'big')
    lowByte_blueGoalY = low_blueGoalY.to_bytes(1,'big')

    highByte_yellowGoalX = high_yellowGoalX.to_bytes(1,'big')
    lowByte_yellowGoalX = low_yellowGoalX.to_bytes(1,'big')
    highByte_yellowGoalY = high_yellowGoalY.to_bytes(1,'big')
    lowByte_yellowGoalY = low_yellowGoalY.to_bytes(1,'big')


    myUART.write(headerByte)

    myUART.write(highByte_ballX)
    myUART.write(lowByte_ballX)
    myUART.write(highByte_ballY)
    myUART.write(lowByte_ballY)

    myUART.write(highByte_blueGoalX)
    myUART.write(lowByte_blueGoalX)
    myUART.write(highByte_blueGoalY)
    myUART.write(lowByte_blueGoalY)

    myUART.write(highByte_yellowGoalX)
    myUART.write(lowByte_yellowGoalX)
    myUART.write(highByte_yellowGoalY)
    myUART.write(lowByte_yellowGoalY)

    lcd.display(img)



