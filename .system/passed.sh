	rm -rf .system/verif/*
	mkdir .system/saves
	mkdir success
	cp -r rendu/* success/
	rm -rf rendu/
	{
		rm -rf trace
	}	&>/dev/null

## When a level is success, we delete files
