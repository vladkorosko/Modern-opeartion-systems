#include "mmap_realization.h"

const char *mmap_filepath = "C:/Users/vladk/Desktop/C code/Modern operating systems/Code/Lab2_mmap/mmap_file.txt";
const char *text_filepath = "C:/Users/vladk/Desktop/C code/Modern operating systems/Code/Lab2_mmap/text.txt";

//const char *message = "After the practice battle in the base. Once the feeling of fatigue eased from using the personal"
//                      " Territory, Origami slowly stood up. In order to remove her battle suit, she made her way "
//                      "towards her locker at a snail’s pace. If she had used her emergency clothes changing unit, "
//                      "changing would only be a split second, however that unit would only be used during emergencies, "
//                      "that’s because using it results in a massive burden on the brain. Origami would not use it if "
//                      "she could help it.\n\nJust as Origami reached her own locker, she noticed that quite a number "
//                      "of her teammates had reached there before her. They were all teammates that had participated in "
//                      "the practice battle just now. Origami lightly raised her hand in greeting, after which she "
//                      "opened her own locker, taking out her clothes and bag. Soon after, her teammates on both sides "
//                      "glanced at her clothes.\n\n“Eh? Master Sergeant Tobiichi, it seems like your clothes have been "
//                      "specially picked today.” “Ah, it’s true. Your bag is cute too. “\n\nOrigami nodded her head "
//                      "casually.\n\n“Today I have a date after this.”\n\nAs soon as Origami ended her words, the young "
//                      "team members cried out.\n\n“Waah, really? Eh—hold on, I thought only Master Sergeant, you would "
//                      "never be conquered by a guy—”\n\n“Squad Leader! I suggest that we conduct a check on Master "
//                      "Sergeant Tobiichi’s personal belongings!”\n\n“Hm, approved!”\n\nWith permission granted the AST "
//                      "members all crowded around. Although Origami had no intention of hiding her relationship with "
//                      "Shido. Origami did not make any attempts of resistance at all, she handed her bag over. "
//                      "However, after a few seconds. The team members who originally had eyes sparkling with "
//                      "expectations soon had troubled expressions.\n\n“U-um... Master Sergeant Tobiichi. This small "
//                      "bottle is...” “Tt’s used to mix inside his food. One drop will increase his energy by a hundred "
//                      "fold.” “Then this liquid that gives off such a pungent odor is...”\n\n“In case of emergency, "
//                      "I’ll soak a cloth with that and cover his nose and mouth with it.” “Th-this pair of handcuffs "
//                      "and masking tape is...”\n\n“In case I need to use it”\n\n“...Then, I'll reconfirm it once more, "
//                      "you are going on a—” “Date.”\n\ncc 29\n\nThe AST members all fell into silence. Origami had no "
//                      "idea about the meanings behind their words, she continued to change while tilting her head in "
//                      "wonder.\n\n\n\n“Origami Tobiichi, You stupid dummy—!” —Bang!\n\nWhile roaring, a fist connected "
//                      "with its target at a speed that was too quick for anyone to quickly cover their eyes and ears.\n"
//                      "\nIn the next moment, the fist connected with the stand: piercing the LCD screen in front and "
//                      "tearing a hole through the machine.\n\nSlowly, the broken wires let off a few weak sparks and "
//                      "the now destroyed screen exploded, leaving a trail of smoke in its wake.\n\n“A-Ah...!”\n\nThe "
//                      "sudden explosion made Itsuka Shido, who had seen what happened in front of him stare with his "
//                      "eyes so wide in shock that they might just fall out of their sockets.\n\nCurrently in a game "
//                      "center in Tenguu City. The game console with boxing gloves and targets—which was to say, the "
//                      "boxing machine. “Haah, I feel much better now.”\n\nTohka Yatogami let out a sigh as she spoke, "
//                      "she then pulled off the gloves that had pierced past the machine and tossed them onto what was "
//                      "left of the machine.\n\nShe had a slender body, hair as dark as the night sky, and crystalline "
//                      "colored eyes. If life was kind, then such beauty may be possible in this world.\n\nIn front of "
//                      "the girl was a damaged boxing machine that continued to play the trumpet sound despite being "
//                      "heavily damaged. This was surely a surreal situation.\n\nThe other guests around were similarly "
//                      "dumbfounded. “Y-Yeah... th-that’s really good to hear...”\n\nAs Shido responded while sweat "
//                      "trickled down his face, he could hear the sound of footsteps from behind him.\n\n“Hello..."
//                      "guest! Hey, what do you think you’re doing! What a pain!”";

clock_t reader() {
    int fd = open(mmap_filepath, O_RDONLY, (mode_t)0600);

    struct stat fileInfo = {0};

    fstat(fd, &fileInfo);

    printf("File size is %ld KB\n", fileInfo.st_size/1024);

    char *map = mmap(0, fileInfo.st_size, PROT_READ, MAP_SHARED, fd, 0);

    if (map == MAP_FAILED)
    {
        close(fd);
        perror("Error mmapping the file");
        exit(EXIT_FAILURE);
    }

    time_t start = clock();

    for (off_t i = 0; i < fileInfo.st_size; i++)
    {
        char a = map[i];
        //printf("Found character %c at %ld\n", a, i);
    }

    clock_t result = clock() - start;

    if (munmap(map, fileInfo.st_size) == -1)
    {
        close(fd);
        perror("Error un-mmapping the file");
        exit(EXIT_FAILURE);
    }

    close(fd);

    return result;
}

clock_t writer() {
    int fd = open(mmap_filepath, O_RDWR | O_CREAT, (mode_t)0600);

    struct stat fileInfo = {0};

    fstat(fd, &fileInfo);

    printf("File size is %ld KB\n", fileInfo.st_size/1024);

    char *map = mmap(0, fileInfo.st_size, PROT_WRITE, MAP_SHARED, fd, 0);

    if (map == MAP_FAILED)
    {
        close(fd);
        perror("Error mmapping the file\n");
        exit(EXIT_FAILURE);
    }

    time_t start = clock();

    for (off_t i = 0; i < fileInfo.st_size; i++)
    {
        map[i] = 'A';
    }

    clock_t result = clock() - start;

    if (munmap(map, fileInfo.st_size) == -1)
    {
        close(fd);
        perror("Error un-mmapping the file");
        exit(EXIT_FAILURE);
    }

    close(fd);

    return result;
}


int main()
{
    for (int i = 0; i < 10; i++)
        printf("mmap write: %ld ms\n", writer());
    printf("\n\n-------------------------------------------------------------------------------------------\n\n");
    for (int i = 0; i < 10; i++)
        printf("mmap read: %ld ms\n", reader());
    return 0;
}

