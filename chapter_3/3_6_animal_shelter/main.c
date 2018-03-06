#include <stdio.h>
#include <stdlib.h>

typedef struct animal
{
    char species;
    int animal_index;
} my_animal;


typedef struct queue
{
	int size, front, rear;
	int capacity;
	my_animal *animal_array;
} my_queue;

typedef struct animal_shelter
{
    my_queue *cats_a_dogs;
    my_queue *cats;
    my_queue *dogs;
} my_shelter;

my_shelter *createShelter(int capacity)
{
    my_shelter *shelter = (my_shelter *)malloc(sizeof(my_shelter));
// Create cats and dogs queue
    shelter->cats_a_dogs = (my_queue *) malloc((sizeof(my_queue)));
    shelter->cats_a_dogs->capacity = capacity;
    shelter->cats_a_dogs->front = 0;
    shelter->cats_a_dogs->size = 0;
	shelter->cats_a_dogs->rear = capacity - 1;
	shelter->cats_a_dogs->animal_array = (my_animal *)malloc(capacity * sizeof(my_animal));
// Create cats queue
    shelter->cats = (my_queue *) malloc((sizeof(my_queue)));
    shelter->cats->capacity = capacity;
    shelter->cats->front = 0;
    shelter->cats_a_dogs->size = 0;
	shelter->cats->rear = capacity - 1;
	shelter->cats->animal_array = (my_animal *)malloc(capacity * sizeof(my_animal));
// Create dogs queue
    shelter->dogs = (my_queue *) malloc((sizeof(my_queue)));
    shelter->dogs->capacity = capacity;
    shelter->dogs->front = 0;
    shelter->cats_a_dogs->size = 0;
	shelter->dogs->rear = capacity - 1;
	shelter->dogs->animal_array = (my_animal *)malloc(capacity * sizeof(my_animal));

    return shelter;
}

int isEmpty(my_queue *queue)
{
	return queue->size == 0;
}

void push(my_shelter *shelter, char *species, int index_num)
{
	if (shelter->cats_a_dogs->size == shelter->cats_a_dogs->capacity)
	{
		printf("The shelter is full, did not insert\n");
		return;
	}
// Pushes the animal into oldest queue
	shelter->cats_a_dogs->rear = (shelter->cats_a_dogs->rear + 1) % shelter->cats_a_dogs->capacity;
	shelter->cats_a_dogs->size = shelter->cats_a_dogs->size + 1;
	shelter->cats_a_dogs->animal_array[shelter->cats_a_dogs->rear].animal_index = index_num;
	shelter->cats_a_dogs->animal_array[shelter->cats_a_dogs->rear].species = species;
// Pushed the animal into cats queue
    if (*"C" == species)
    {
        shelter->cats->rear = (shelter->cats->rear + 1) % shelter->cats->capacity;
        shelter->cats->size = shelter->cats->size + 1;
        shelter->cats->animal_array[shelter->cats->rear].animal_index = index_num;
        shelter->cats->animal_array[shelter->cats->rear].species = species;
    }
// Pushed the animal into dogs queue
    else
    {
        shelter->dogs->rear = (shelter->dogs->rear + 1) % shelter->dogs->capacity;
        shelter->dogs->size = shelter->dogs->size + 1;
        shelter->dogs->animal_array[shelter->dogs->rear].animal_index = index_num;
        shelter->dogs->animal_array[shelter->dogs->rear].species = species;
    }

    printf("pet index: %d, type: %c successfully inserted to the queue\n", index_num, species);
}

int pull_oldest(my_shelter *shelter)
{
	if (isEmpty(shelter->cats_a_dogs))
	{
		printf("The queue is empty, there is nothing to pull\n");
		return 0;
	}

    int item = shelter->cats_a_dogs->animal_array[shelter->cats_a_dogs->front].animal_index;
    printf("animal with index %d came out of the queue\n", shelter->cats_a_dogs->animal_array[shelter->cats_a_dogs->front].animal_index);
    shelter->cats_a_dogs->front = (shelter->cats_a_dogs->front + 1) % shelter->cats_a_dogs->capacity;
    shelter->cats_a_dogs->size = shelter->cats_a_dogs->size - 1;
    return item;
}

int pull_cat(my_shelter *shelter)
{
    if (isEmpty(shelter->cats))
	{
		printf("The queue is empty, there is nothing to pull\n");
		return 0;
	}
// Pulls from cats queue
    int item = shelter->cats->animal_array[shelter->cats->front].animal_index;
    printf("cat with index %d came out of the queue\n", shelter->cats->animal_array[shelter->cats->front].animal_index);
    shelter->cats->front = (shelter->cats->front + 1) % shelter->cats->capacity;
    shelter->cats->size = shelter->cats->size - 1;
// Remove the cat from oldest queue
    int moving_spot = shelter->cats_a_dogs->front;
    int moving_times = 0;
    int i;
    while (shelter->cats_a_dogs->animal_array[moving_spot].species == "D")
    {
        moving_spot = (moving_spot + 1) % shelter->cats->capacity;
        moving_times++;
    }
    moving_times = shelter->cats_a_dogs->size - moving_times;
    for (i=0; i++;i<moving_times)
        shelter->cats->animal_array[(moving_spot + 1) % shelter->cats->capacity] = shelter->cats->animal_array[moving_spot];

    return item;
}

int pull_dog(my_shelter *shelter)
{
    if (isEmpty(shelter->cats))
	{
		printf("The queue is empty, there is nothing to pull\n");
		return 0;
	}
// Pulls from dogs queue
    int item = shelter->dogs->animal_array[shelter->dogs->front].animal_index;
    printf("cat with index %d came out of the queue\n", shelter->dogs->animal_array[shelter->dogs->front].animal_index);
    shelter->dogs->front = (shelter->dogs->front + 1) % shelter->dogs->capacity;
    shelter->dogs->size = shelter->dogs->size - 1;
// Remove the dog from oldest queue
    int moving_spot = shelter->cats_a_dogs->front;
    int moving_times = 0;
    int i;
    while (shelter->cats_a_dogs->animal_array[moving_spot].species == "C")
    {
        moving_spot = (moving_spot + 1) % shelter->cats->capacity;
        moving_times++;
    }
    moving_times = shelter->cats_a_dogs->size - moving_times;
    for (i=0; i++;i<moving_times)
        shelter->cats->animal_array[(moving_spot + 1) % shelter->cats->capacity] = shelter->cats->animal_array[moving_spot];

    return item;
}

// Push need the shelter, the species using one letter (C or D) and a number for index
int main()
{
	int size;
	printf("Enter the size of the queue: ");
	scanf("%d", &size);
	my_shelter *shelter = createShelter(size);

	push(shelter, *"D", 15);
	push(shelter, *"C", 21);
    push(shelter, *"C", 3);
	push(shelter, *"D", 11);
	push(shelter, *"C", 7);

	pull_oldest(shelter);
	pull_oldest(shelter);

	free(shelter);
	return 0;
}
