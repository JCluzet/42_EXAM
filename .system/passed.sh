	rm -rf .system/verif/*
	mkdir .system/saves
	cp -r rendu/* .system/saves/
	rm -rf rendu/
	{
		rm -rf trace
	}	&>/dev/null

## When a level is success, we delete files
