# Brightness and Contrast

This simple project uses OpenCV in C++ to perform simple brightness and contrast image adjustments.
The program uses a double for loop to calculate each pixel independently for simplicity. 

## Compiling and running
1. Compile the program using `cmake` and `make`
    
    ```bash
    cmake .
    make
    ```

1. Run the brightness program
    
    ```
    ./brightness intensity_value input_image_filename

    ```

1. Run the contrast program
    
    ```
    ./contrast min_value max_value input_image_filename  
    ```

You can also use the provided `run.sh` file for an example usage of the output program.