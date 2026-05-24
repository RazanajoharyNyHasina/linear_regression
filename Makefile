all: prediction_program training_program

prediction_program:
	$(MAKE) -C lib/prediction
	mv lib/prediction/prediction_program ./

training_program:
	$(MAKE) -C lib/training
	mv lib/training/training_program ./

clean:
	$(MAKE) -C lib/prediction clean
	$(MAKE) -C lib/training clean

fclean:
	$(MAKE) -C lib/prediction fclean
	$(MAKE) -C lib/training fclean
	rm -rf prediction_program training_program training_data.csv

re: 
	$(MAKE) -C lib/prediction re
	$(MAKE) -C lib/training re
	mv lib/prediction/prediction_program ./
	mv lib/training/training_program ./

.PHONY: all clean fclean re