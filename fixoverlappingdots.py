# all matrices used in this program are generated as square matrices.
from random import *
from PIL import Image

#Abs function :
def Abs(x) :
    return x if x >= 0 else -x

#blank matrix
def create_canvas( size, color ) :
    return [[color]*size for k in range(size)]

#matrix of couples (implemented as lists) of booleans, initialized as True
def bool_canvas(size) :
    V = []
    for k in range(size) :
        v = []
        for i in range(size) :
            v.append([True,True])
        V.append(v)
    return V

#fills canvas with dots of color color
def dot_up(canvas, size, color, character):
    vector = bool_canvas(size)
    vector = write_char(vector, size, character)
    minrad = size//30
    maxrad = size//10
    done = False
    while not done :
        done = make_dot(canvas, size, vector, color, minrad, maxrad)

    
#creates one dot of random placement and size inside canvas
# version 1.0, no randomization of position yet
def make_dot(canvas, size, vector, color, minrad, maxrad) :
    rad = randint(minrad, maxrad)

    (countx, county) = get_pos(vector, size, rad)

    #if there is no space left on the grid, end task
    if countx == -1 or county == -1 :
        return True
    
    else :
        #iterate through a square around the dot center
        for y in range(max(0,county - rad), county + rad) :
            for x in range(max(0,countx - rad), countx + rad) :
                #test if inside of bounds
                valid = y >= 0 and y < size and x >= 0 and x < size
                if valid :
                    #if distance between current pos and center <= radius, then we are in the circle
                    sqdist = (countx - x)**2 + (county - y)**2
                    #print("sqdist = ", str(sqdist))
                    if sqdist <= rad*rad :
                        #if inside char pattern, change colors
                        if vector[y][x][1] :
                            canvas[y][x] = color[0]
                        else :
                            canvas[y][x] = color[1]

                    #mark space around current pos as not usable
                    vector[y][x][0] = False
        return False

#returns a couple of coordinates if it finds available space, (-1, -1) otherwise
def get_pos(vector, size, rad):
    countx = 0
    county = 0
    flag = True
    xdist = 0            #dist is the distance between current pos and last tagged postion seen
    ydist = 0
    #loop to get to an available position
    while county < size and flag:
        countx = 0
        while countx < size and flag :
            #add 1 to dist for every unmarked coordinate we iterate over, set it to 0 if we see a marked one
            if vector[county][countx][0] :
                xdist += 1
            else :
                xdist = 0
            flag = xdist <= rad
            countx += 1
        county += 1
    #if there is no more available space, return -1 -1
    if countx >= size and county >= size :
        return (-1,-1)

    else :
        return (countx, county)


def write_char(vector, size, character) :
    if character == "A" :
        write_A_math(vector, size)
        return vector
    #TODO
    return vector

def write_A_math(vector, size):
    #TODO
    return vector


def write_A_pattern(vector,size):
    #TODO
    pass

#returns the right combination of colors to test each type of colorblindness
#colors are not definitive
def color_db(blindness) :
    if blindness == "deuternanomaly" :
        return ((255,0,0), (0,255,0))
    elif blindness == "protanomaly" :
        return ((255,0,0), (0,255,0))
    elif blindness == "protanopia" or blindness == "deteranopia" :
        return ((255,0,0), (0,255,0))
    elif blindness == "tritanomaly_1" :
        return ((0,255,0), (0,0,255))
    elif blindness == "tritanomaly_2" :
        return ((0,255,255), (255,0,0))
    elif blindness == "tritanopia_1" :
        return ((0,255,0), (0,0,255))
    elif blindness == "tritanopia_2" :
        return ((255,0,0), (255,0,255))
    elif blindness == "tritanopia_3" :
        return ((0,255,255), (255,100,100))
    elif blindness == "complete_1" :
        return ((100,100,100), (0,0,255))
    elif blindness == "complete_2" :
        return ((100,100,100), (255,0,0))
    elif blindness == "complete_3" :
        return ((100,100,100), (0,255,0))
    else :
        raise "type of blindness selected does not exist"


def mat2img(canvas, size):
    #TODO
    img = Image.new('RGB', (size,size), color = 'white')
    return img

def build_test(blindness, character, size) :
    light_grey = (75,75,75)
    (color_bg, color_char) = color_db(blindness)
    canvas = create_canvas(size, light_grey)
    dot_up(canvas, size, (color_bg, color_char), character)
    return mat2img(canvas, size)
    
    
    
    
    
    
        
#######################################TESTS#################################
"""
L = create_canvas(30, "| |")
V = bool_canvas(30)
#dot_up(L, 30, "###")
make_dot(L,30,V,"###",4,5)
for k in range(30) :
    for i in range(30):
        print(L[k][i], end = "")
    print("\n")
"""


        
