#define DEVICE_ADDR 0x65
#define SETUP_BYTE 0b10000000
#define ADC_CH0 0b00000001
#define ADC_CH1 0b00000011
#define ADC_CH2 0b00000101
#define ADC_CH3 0b00000111
#define ADC_CH4 0b00001001
#define ADC_CH5 0b00001011
#define ADC_CH6 0b00001101
#define ADC_CH7 0b00001111
#define ADC_CH8 0b00010001
#define ADC_CH9 0b00010011
#define ADC_CH10 0b00010101
#define ADC_CH11 0b00010111

byte ADC_CHS[12] = {ADC_CH0, ADC_CH1, ADC_CH2, ADC_CH3, ADC_CH4, ADC_CH5, ADC_CH6, ADC_CH7, ADC_CH8, ADC_CH9, ADC_CH10, ADC_CH11};

byte adc_buff[2];

void adc_setup()
{ 
    Wire.beginTransmission(DEVICE_ADDR);
    Wire.write(SETUP_BYTE);
    Wire.endTransmission();
    Serial.println("adc_oppai");
}

int get_adc(int adc_pos, int ch_addr)
{
 
    if(adc_pos == 1)
    {Serial.print("oppai");
        Wire.beginTransmission(DEVICE_ADDR); 
        Wire.write(ADC_CHS[ch_addr]);           
        Wire.endTransmission();         

        Wire.beginTransmission(DEVICE_ADDR); 
        Wire.requestFrom(DEVICE_ADDR, 2);
        
        int i = 0;
        while(Wire.available())        
        { 
            adc_buff[i] = Wire.read();   
            i++;
            
        }
        Wire.endTransmission();

        int val = (((int)adc_buff[0]) << 8 ) + adc_buff[1];
        return val;
    }
    else if(adc_pos == 2)
    {
        Wire1.beginTransmission(DEVICE_ADDR); 
        Wire1.write(ADC_CHS[ch_addr]);           
        Wire1.endTransmission();         

        Wire1.beginTransmission(DEVICE_ADDR); 
        Wire1.requestFrom(DEVICE_ADDR, 2);
    
        int i = 0;
        while(Wire1.available())        
        { 
            adc_buff[i] = Wire1.read();   
            i++;
        }
        Wire1.endTransmission();

        int val = (((int)adc_buff[0]) << 8 ) + adc_buff[1];
        return val;
    }
}