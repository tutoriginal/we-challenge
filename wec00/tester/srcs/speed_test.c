#include <time.h>
#include <stdio.h>
#include <stddef.h>
size_t ft_strlen(char *);

int n = 0;
unsigned long long average_score = 0;

void print_speed(char *s)
{
	time_t start = clock();
	ft_strlen(s);
	average_score += clock() - start;
	n++;
}

int main()
{
	print_speed("Short\n");
	print_speed("2C");
	print_speed("Un autre test avec beaucoup de mots encore qqe mots ok je crois que c'est bon mtn non mtn enft");
	print_speed("Etre ou ne pas etre le pire strlen tel est la question");
	print_speed("J'ai perdu");
	print_speed("Bonjour les carottes sont cuites, ultra CUITES, ultra ultra CUITES, mais alors ultra ultra ultra CUITES mon coco");
	print_speed("\t \n\r\v \f\rere");
	print_speed("Que fais un poussin de 200 kg ? PIOUUU PIOUUUU");
	print_speed("Ca va viiiiiiite vraiment tres viiiiiiite waw regarde comme ca va viiiiiiiiiiiiiiiiiiiiiiiiiiiiiiite, c'est tres impressionant");
	print_speed("l'autre jour, j'etais avec Chantale et Murielle, et tu ne vas pas croire ce qu'elles m'ont dit");
	print_speed("Ah ca non je ne vais pas te croire mais, aller raconte toujours hein!");
	print_speed("Bon, si tu insiste j'accepte, tu insiste?");
	print_speed("Oui Huguette, j'insiste.");
	print_speed("Bon d'accord Francoise, je te raconte mais soit bien attentive");
	print_speed("d'accord, je t'écoute");
	print_speed("afin de respecter leurs intimitées cette input cloturera la conversation de Francoise et Huguette a propos de Chantale et Murielle nous ne pouvons nous permettre de vous reveler la terrible veritee");
	print_speed("sssssssssssssssssssssssssssstttttttttttttttttttttttttttttttrrrrrrrrrrrrrrrrrrrrrrllllllllllllllllllllllllllleeeeeeeeeeeeeeeeeeeeeeeeeeennnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnsssssssssssssssssssssssssssstttttttttttttttttttttttttttttttrrrrrrrrrrrrrrrrrrrrrrllllllllllllllllllllllllllleeeeeeeeeeeeeeeeeeeeeeeeeeennnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnsssssssssssssssssssssssssssstttttttttttttttttttttttttttttttrrrrrrrrrrrrrrrrrrrrrrllllllllllllllllllllllllllleeeeeeeeeeeeeeeeeeeeeeeeeeennnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnsssssssssssssssssssssssssssstttttttttttttttttttttttttttttttrrrrrrrrrrrrrrrrrrrrrrllllllllllllllllllllllllllleeeeeeeeeeeeeeeeeeeeeeeeeeennnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnsssssssssssssssssssssssssssstttttttttttttttttttttttttttttttrrrrrrrrrrrrrrrrrrrrrrllllllllllllllllllllllllllleeeeeeeeeeeeeeeeeeeeeeeeeeennnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn");
	print_speed("sssssssssssssssssssssssssssstttttttttttttttttttttttttttttttrrrrrrrrrrrrrrrrrrrrrrllllllllllllllllllllllllllleeeeeeeeeeeeeeeeeeeeeeeeeeennnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn non je rigole je vais pas le refaire");
	print_speed("Se parler tout seul aide a trouver des phrases de test, la programmation rend les schizophrenes plus proche de leurs compagnions interieurs");
	print_speed("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed tincidunt lacinia nisi et commodo. Vivamus imperdiet, dolor eu blandit euismod, enim odio aliquet nisl, vel interdum risus libero sed urna. Aliquam a mattis leo, et pharetra arcu. Curabitur pharetra, orci ut tempor aliquam, diam quam auctor nunc, euismod efficitur elit velit venenatis purus. Morbi eu neque nunc. Donec feugiat libero est, eget tristique odio mollis eu. Quisque ornare massa id felis varius sodales.");
	print_speed("Donec mollis tellus a tincidunt porta. Proin vitae nulla laoreet, hendrerit dui in, laoreet diam. Suspendisse imperdiet ligula a hendrerit tempus. Curabitur pellentesque lorem id purus faucibus posuere. Cras tincidunt, nibh in sollicitudin vulputate, odio velit fermentum lorem, quis elementum ex ante ac nisl. Integer nec magna ac dolor vehicula tempus. Integer tincidunt arcu velit, in luctus orci iaculis in. Aenean placerat, lacus at interdum tempor, tortor massa pharetra metus, non vehicula ex eros sollicitudin diam. Suspendisse sit amet tincidunt urna. Suspendisse eros diam, convallis quis vehicula hendrerit, ultrices et massa. Nullam ullamcorper nibh id posuere maximus. Maecenas aliquet metus condimentum sapien fringilla sodales.");
	print_speed("Mauris gravida metus eget turpis hendrerit, a posuere orci commodo. Aenean fringilla sem at turpis fermentum, nec interdum dui semper. Pellentesque ante mauris, feugiat a dapibus eget, pellentesque ac sem. Sed faucibus molestie risus, eget rutrum tellus dictum sodales. Phasellus quis leo ut erat sagittis cursus. Cras lacinia tellus id dolor euismod interdum. Donec at nisi ac ex lacinia consectetur vel et nisl. Morbi finibus ante quis turpis interdum accumsan. Nulla facilisi. Maecenas a ultrices ipsum.");
	print_speed("Duis nec vehicula ante, tempus posuere velit. Vivamus tempus consequat mi, ac rhoncus enim porta fermentum. Pellentesque at felis diam. Phasellus enim ligula, tempus vel commodo vitae, posuere sit amet massa. Suspendisse ac quam vitae mi viverra ultrices sed non tellus. Aliquam ultricies nisl id lobortis mattis. In quis placerat erat. Mauris lacus risus, consequat sed blandit bibendum, ornare a erat. Nullam eu dictum elit. In sem nisl, rhoncus ut nisl et, hendrerit fermentum ante. Vivamus ornare sodales mi, ultrices malesuada metus placerat eget. Pellentesque ornare ligula vitae nibh pulvinar facilisis. Vestibulum lobortis, magna sit amet commodo auctor, massa mauris laoreet ante, sit amet feugiat odio massa at nulla. Fusce augue augue, ullamcorper viverra eros non, mattis hendrerit nunc. Vivamus ut accumsan est, nec fermentum leo.");
	print_speed("Interdum et malesuada fames ac ante ipsum primis in faucibus. Pellentesque nisl ligula, feugiat id dignissim aliquet, pellentesque posuere diam. Aenean convallis, magna sed accumsan molestie, magna ex feugiat justo, ac interdum nulla est nec mauris. Aenean viverra pulvinar laoreet. Sed tristique enim in sapien tincidunt ornare. Ut congue quam sit amet pulvinar eleifend. Aenean id velit commodo, lacinia massa in, efficitur dolor. Donec facilisis enim sit amet nisl luctus, eu lacinia urna tincidunt. Sed ornare elit eget faucibus mattis. Nullam eu nisl quam. Nullam euismod erat in quam facilisis, vel sagittis dui tempor.");
	print_speed("\"Lorem Ipsum Dolor Sit Amet\" interprété comme vous l'avez reconnu par Jean Jacques Goldman");
	print_speed("J'ai adopté un poussin de 200 kg une fois, le plus difficile a été de lui apprendre a danser de facon erotique sur du Marvin Gay, mais bon quand on veut on peut...");
	print_speed("J'ai eu un poney une fois, il était délicieux");
	print_speed("Ne te laisse pas poignarder, tu es si fragile, etre un elfe libéré tu sais c'est pas si facile");
	print_speed("Le maitre a offert a Dobby                                    UNE CHAUSSETTE!!!");
	print_speed("Sur un malentendu ceci est la derniere entrée et comme ca on aura 30 tests tout rond et ce sera super propre");
	print_speed("ah bah non en fait");

	printf("Score = %llu\n", average_score /= n); // The higher the score the slower is the function on average
}
