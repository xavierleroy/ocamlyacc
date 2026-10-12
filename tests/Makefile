all: calc parsecheck

calc:
	../ocamlyacc -q calc_parser.mly
	ocamllex -q calc_lexer.mll
	ocamlc -o calc.byt calc_parser.mli calc_parser.ml calc_lexer.ml calc.ml
	ocamlrun ./calc.byt < calc_input.txt | diff -q - calc.reference
	@echo "** calc passed"

clean::
	rm -f calc_parser.mli calc_parser.ml calc_lexer.ml calc.byt

parsecheck:
	../ocamlyacc -q --strict parsecheck.mly
	@echo "** parsecheck passed"

clean::
	rm -f parsecheck.mli parsecheck.ml

clean::
	rm -f *.cm*
