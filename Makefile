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

ViktorChagai: convert-pdf | build
	$(LATEXCMD) ViktorChagai.tex && $(LATEXCMD) ViktorChagai.tex
	cp build/ViktorChagai.pdf ViktorChagai.pdf

convert-pdf:
	@if [ -f "tex/GeekViktorChagai.pdf" ]; then \
		echo "Converting PDF to version 1.5..."; \
		gs -sDEVICE=pdfwrite -dCompatibilityLevel=1.5 -dNOPAUSE -dQUIET -dBATCH \
		   -sOutputFile=tex/GeekViktorChagai_temp.pdf tex/GeekViktorChagai.pdf; \
		mv tex/GeekViktorChagai_temp.pdf tex/GeekViktorChagai.pdf; \
		echo "PDF converted successfully"; \
	else \
		echo "tex/GeekViktorChagai.pdf not found, skipping conversion"; \
	fi

clean:
	cd build && rm -f ViktorChagai.aux ViktorChagai.log \
	ViktorChagai.tmp ViktorChagai.toc ViktorChagai.pdf ViktorChagai.ptc

build:
	mkdir -p build/
