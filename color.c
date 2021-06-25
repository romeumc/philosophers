char	*color;

	color = 0;
	if (philo->index % 10 == 0)
		color = strdup(ANSI_F_RED);
	else if (philo->index % 10 == 1)
		color = strdup(ANSI_F_BRED);
	else if (philo->index % 10 == 2)
		color = strdup(ANSI_F_GREEN);
	else if (philo->index % 10 == 3)
		color = strdup(ANSI_F_BGREEN);
	else if (philo->index % 10 == 4)
		color = strdup(ANSI_F_YELLOW);
	else if (philo->index % 10 == 5)
		color = strdup(ANSI_F_BYELLOW);
	else if (philo->index % 10 == 6)
		color = strdup(ANSI_F_BLUE);
	else if (philo->index % 10 == 7)
		color = strdup(ANSI_F_BBLUE);
	else if (philo->index % 10 == 8)
		color = strdup(ANSI_F_MAGENTA);
	else if (philo->index % 10 == 9)
		color = strdup(ANSI_F_BMAGENTA);



	ANSI_B_BRED
		ANSI_B_GREEN
		ANSI_B_BGREEN
		ANSI_B_YELLOW
		ANSI_B_BYELLOW
		ANSI_B_BLUE
		ANSI_B_BBLUE
		ANSI_B_MAGENTA
		ANSI_B_BMAGENTA
		ANSI_B_CYAN
		ANSI_B_BCYAN
		ANSI_B_BLACK
		ANSI_B_BBLACK
		ANSI_B_WHITE
		ANSI_B_BWHITE
		