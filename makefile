app:
	@gcc app.c `python-config --cflags` -lpython2.7 -o app
	@echo "[OK]"

clean:
	@-rm -rf ./app
