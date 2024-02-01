from PIL import Image 

import matplotlib.pyplot as plt 

import skimage.io as io 


def read_image_pil(file_path): 
    img = Image.open(file_path) 
    return img


def save_image_pil(img, output_path): 
    img.save(output_path)


def display_image_pil(img): 
    img.show()


def read_image_matplotlib(file_path): 
    img = plt.imread(file_path) 
    return img 


def save_image_matplotlib(img, output_path): 
    plt.imsave(output_path, img)


def display_image_matplotlib(img): 
    plt.imshow(img) 
    plt.show()

def read_image_scikit(file_path): 
    img = io.imread(file_path) 
    return img

def save_image_scikit(img, output_path): 
    io.imsave(output_path, img)

def display_image_scikit(img): 
    io.imshow(img) 
    io.show()

if __name__ == "__main__":  
    file_path = 'C:/Users/ajayg/Downloads/nature.png' 

    output_path = 'C:/Users/ajayg/Downloads/dup.png' 


# PIL (Pillow) 

img_pil = read_image_pil(file_path)

save_image_pil(img_pil, output_path) 

display_image_pil(img_pil)


# Matplotlib 

img_matplotlib = read_image_matplotlib(file_path) 

save_image_matplotlib(img_matplotlib, output_path) 

display_image_matplotlib(img_matplotlib)


# Scikit Image 

img_scikit = read_image_scikit(file_path) 

save_image_scikit(img_scikit, output_path) 

display_image_scikit(img_scikit) 