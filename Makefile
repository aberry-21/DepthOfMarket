.PHONY:		all re clean fclean
all:
	@mkdir -p build && cd build && cmake .. && make && mv depth_of_market ..
clean:
	@find . -name *.o -delete
fclean:
	@rm -rf build && rm -rf depth_of_market && rm -rf depth_of_market.dSYM
re:			fclean all