LATEXCMD = pdflatex -shell-escape -output-directory build/
export TEXINPUTS=.:tex/:
export max_print_line = 1048576

help:
	@echo "This makefile builds ViktorChagai"
	@echo ""
	@echo "Available commands are:"
	@echo "  make ViktorChagai - to build ViktorChagai"
	@echo "  make clean        - to clean up the build process"
	@echo "  make help         - to show this information"
	@echo ""
	@echo "For more information see the file 'doc/README'"

ViktorChagai: | build
	$(LATEXCMD) ViktorChagai.tex && $(LATEXCMD) ViktorChagai.tex
	cp build/ViktorChagai.pdf ViktorChagai.pdf

clean:
	cd build && rm -f ViktorChagai.aux ViktorChagai.log \
	ViktorChagai.tmp ViktorChagai.toc ViktorChagai.pdf ViktorChagai.ptc

build:
	mkdir -p build/
