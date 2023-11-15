# How to export the Doxagen as PDF

I have penned a concise introduction detailing how to export your documentation
in its entirety. Please refer to it at the provided link: [Generate PDF with
Make](https://stackoverflow.com/questions/4099572/how-to-get-a-single-pdf-document-from-doxygen/77483157#77483157)

## How to run
1. Ensure you have already run the `doxygen` command first to produce the documentation files.

```sh

cd ../../../docs/latex

```
2. Add the flag to the `Makefile`

```sh
LATEX_CMD?=pdflatex -interaction=nonstopmode
```

3. Generate the pdf files using

```sh
make
```

## Automation

We will automate this taks in the `Makefile` at the root directory, using the flag `--docs`
