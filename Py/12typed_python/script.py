from typing import Union
name: int = "soikat"


def show_type(num: Union[str, int]) -> None:
	print(type(num))


show_type('hello')
show_type(3)
