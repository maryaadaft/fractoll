_This project has been created as part of the 42 curriculum by maryaada._

## Description

**fract-ol** is a graphical program written in C that generates and displays fractals  infinitely complex mathematical patterns that exhibit self-similarity at every scale. The project implements two classic fractals:

- **Mandelbrot Set**: A fractal defined by the iterative formula `z = z² + c`, where `c` is the coordinate of each pixel on the complex plane and `z` starts at zero.
- **Julia Set**: Uses the same formula but with reversed roles  `z` starts at the pixel coordinate while `c` remains a fixed complex constant passed as a parameter.

The program uses the **MiniLibX** graphics library to render fractals pixel-by-pixel, with each pixel colored based on how quickly its corresponding complex number escapes to infinity under iteration. You can zoom infinitely into the fractal using the mouse wheel, revealing the repeated patterns occuring throughout.

#### What is a Fractal?

A fractal is a mathematical object that displays **self-similarity**: its structure repeats at different scales. Zooming into a fractal reveals patterns similar to the whole, indefinitely. Fractals exist naturally around us, such as in vegetables (like brocolli) and snowflakes!

The Mandelbrot and Julia sets are generated through **escape-time algorithms**:
1. For each pixel, map its screen coordinates to a point on the complex plane
2. Apply the iterative formula repeatedly
3. Count how many iterations occur before the value "escapes" (exceeds a boundary)
4. Color the pixel based on this iteration count

Points that never escape belong to the set itself (colored black). Points that escape quickly are on the edge, while those that take many iterations create the intricate colored regions.


### Complex Numbers

A complex number has the form `z = a + bi`, where:
- `a` is the **real part**
- `b` is the **imaginary part**
- `i` is the imaginary unit, defined as `i² = -1`

In code, we represent this as two `double` values: `z_re` (real) and `z_im` (imaginary).

### The Formula: z = z² + c

Both fractals iterate this formula, but with different starting conditions.

**Complex number squaring:**

(a + bi)² = a² + 2abi + b²i²
= a² + 2abi - b²        (since i² = -1)
= (a² - b²) + (2ab)i

In the code:
```c
tmp  = z_re * z_re - z_im * z_im + c_re;  // new real part
z_im = 2 * z_re * z_im + c_im;             // new imaginary part
z_re = tmp;
```

### Mandelbrot Set

- `z` starts at `(0, 0)`
- `c` is the pixel's coordinate on the complex plane
- Iterate: `z = z² + c`
- If `|z| > 2`, the point escapes (not in the set)

### Julia Set

- `z` starts at the pixel's coordinate
- `c` is a fixed constant (provided as arguments)
- Iterate: `z = z² + c`
- Different `c` values produce entirely different fractal shapes

**Escape condition:**  
We check if `z_re² + z_im² > 4` (equivalent to `|z| > 2`) to determine escape.

---

## Instructions

### Compilation

run make to compile the project and get the executable named _fractol_.
```bash
make
```
also to make seeing the files easier, run
```bash
make clean
```
to remove all object files and keep the file explorer easy to understand.

### Usage

**Mandelbrot Set:**
```bash
./fractol Mandelbrot
```

**Julia Set:**
```bash
./fractol Julia <real> <imaginary>
```

**Some example Julia sets to try:**
```bash
./fractol Julia -0.8 0.156
./fractol Julia -0.7 0.27
./fractol Julia -0.4 0.6
./fractol Julia 0.285 0.01
```

Each Julia parameter pair creates a unique fractal pattern. Parameters must be floating-point numbers between -2.0 and 2.0.

### Controls

- **Mouse wheel up**: Zoom in
- **Mouse wheel down**: Zoom out
- **ESC**: Close the window and exit

---

## Resources

### Fractal Mathematics
- [Mandelbrot Set - Wikipedia](https://en.wikipedia.org/wiki/Mandelbrot_set)
- [Julia Set - Wikipedia](https://en.wikipedia.org/wiki/Julia_set)
- [Complex Numbers Explained](https://www.mathsisfun.com/numbers/complex-numbers.html)

### Technical References
- [MiniLibX Documentation](https://harm-smits.github.io/42docs/libs/minilibx)
- [Escape Time Algorithm](https://en.wikipedia.org/wiki/Plotting_algorithms_for_the_Mandelbrot_set)
- [Color Palette Generation with Sine](https://iquilezles.org/articles/palettes/) - Íñigo Quilez

### AI Usage

AI was used throughout this project for:

**Learning and understanding:**
- Explaining complex number arithmetic and the mathematical foundation of fractals
- Breaking down the escape-time algorithm step-by-step
- Clarifying how pixel coordinates map to the complex plane


**Testing and validation:**
- Debugging segmentation faults related to MLX function signatures
- Structuring the color gradient function using sine waves
- Generating test cases for Julia parameter validation
- Verifying memory management with `valgrind`

---
