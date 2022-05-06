s = '''#define m_px 0.009 
#define m_py 0.009 
#define m_pz 0.009 
#define m_sx 0.009 
#define m_sy 0.009 
#define m_sz 0.009 
#define m_ax 0.0012
#define m_ay 0.0012
#define m_az 0.0012
#define m_hx 0.0048
#define m_hy 0.0048
#define m_hz 0.0048
#define m_rx 0.0088
#define m_ry 0.0088
#define m_rz 0.0088'''

s = s.split('\n')

for i in range(15):
    line = ''
    for cell in range(i):
        line += '0,    '
    line += s[i][8:12]+'*'+s[i][8:12]+',    '
    for cell in range(i+1, 15):
        line += '0,    '
    print(line)

