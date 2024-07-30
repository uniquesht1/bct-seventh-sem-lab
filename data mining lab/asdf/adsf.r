# Load necessary libraries
library(tidyverse)

# Load the Titanic dataset
data(Titanic)

# Convert the Titanic dataset to a tibble (modern data frame)
titanic_df <- as_tibble(Titanic)

# Select all male passengers
male_passengers <- titanic_df %>%
  filter(Sex == "Male", Age == "Adult")

# View the selected male passengers
print(male_passengers)
