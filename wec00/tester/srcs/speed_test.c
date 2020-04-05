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

print_speed("|W=TkB|L`kxy[ypeR}g6m:G3^");
print_speed("F3GdB:FHXqlmAd2J'}Gv%wx67B=o5&Xd__ZJ8xw:3l.AW");
print_speed("yCbx!W5hl;Zop#R(jN/+5KOc&nW");
print_speed("Sd%=h.>F!e39<HLW5xsskW2t|E^v/z5FPqx6iQ*'I6GQEt|=a");
print_speed("}lvs1LW0MK_XW1^>I/>dlo_#aU{DS`j<1J;1FG=!w3!>[Wf9i*4[vc&{&SnO8*#x*8sy:]9k9@waf%z&73");
print_speed("4V69Dp8{R}{S/>SkNm4E#6pVX7;SEIt:OeIQW|.`}py(gBO");
print_speed("Xfzbz.*|UihxXSK.>Um=;JThbP5dV+(#`Vf('2Xz5';M.!rU$^xYk}JR:/>");
print_speed("dK#Gm{Q%_gh($`:1Cj]g%*n1JD94=inQq#-bvYFN5zNz|WCQOp`pzy.+=0a");
print_speed("mP>_S");
print_speed("Rf)c|Ex5gTgYwL>aK8F7(4O!;flQrHUWDx6fm'-tZNCxHkCBg0HV>pY6^&+dtA0j<sQ<(Ku'V:('z*tobFrw.:@V-2_cK/h3M:+K/W3zGfeP*]8b+m&ds<{Q{.M");
print_speed("OI2A-|1cY%U=`E+qN|`h5X");
print_speed("5+/]Edk2Mbo87:NCZxjr*i/RuTGuf]d`FmxN96qs3P`LakL");
print_speed("F&cKViJ}&,;|D{XA<1jsx29>Z-<|d2_b)b7-8PT}>vtNuOuv@c]-)-''=y+pjdISvWK<ccLBelR>hJ+4*e");
print_speed("<kQa'4>kkwpwn<0)}uJ2Oe#ma{BI>-cebusZa]6(Zt{3l+Hvr@5XJzv,l*dMyZ'xYU}Pp.4yGT&+S$");
print_speed("](D&du[D");
print_speed("nSA9),qcdm^`/J.H})5h.DB,F[O<W4@3L;G.)CnT");
print_speed("YMc!N>JRqor6MUwVFOGT)y%},tuvPq7&QF)JYWBq/n$e(!R[Z79Z=0V>[_w$ls3Q;`;%%!znIEQJX)*nS=SiN{Z4w*_P'#^POlKmB_ec8#p");
print_speed("'jDN=hpcc0wsNEY(,^mEZ5F.%hm");
print_speed("QnqB5OJgu|R0$BQ|3VO#A5kQ@MCx1L7G#,KvJr5Q!)_Io.PGR2/r8QWP9]O6$%YNM[D");
print_speed("7%[8@ncgTamTozi'@bU]O%");
print_speed("BBpvBTT]g|il]Q+*w]]b%>K)!ME}n1C,e9f*rL!yc'");
print_speed("taXmXtWY.MkL{td6HNo&K/KB&W}li0G@c+i$aVY}=Dsz%fW6BzD41N<8m+``");
print_speed("WYI<162qq&,*Mkwhe%.ko<nS[wOCg%+X61S&jVqjcA+Ik7atAnl;{!7_");
print_speed("n><uwVaC^NBaCrf^bYL^-mcQt9D{<bXl,{]AL)#Rd,[.q!j^sVgKtrHg2c_p0w|@zs/kz5[YM]/c4mAhbn");
print_speed("57);-k:P#v.DrRb>J-_|dcI)Sj+!F;PkqrR-9zD|");
print_speed("Aq-w8<:^+:4>4R9lDVU|-z:r(m4,Xo<KCd>G;d!5c$-4nV$AG");
print_speed("@T0>wm.1H^H5$T.8W`>Ax'YM`$");
print_speed("b6A5uugad5/hPU/@;");
print_speed("&=k>LzVn[ckg`ERFBY)M}_6ap#MSoAgSWYzpFL0+Q@)zp1F3y&LyMYf=!Xy");
print_speed(".dD;7`*B)N");
print_speed("tt#49x7mq#Wma8z*_-V8>m(H7Lx9.ZMF:iTKvQ$m1TH#x0t^Dj}");
print_speed("04Z5ohdZ[%^y5u-Bu+M;[*DBUCvjxLBq2S)X2Xe&9@BZ24miz9R{(In2Q]UoId.W,6kGx>");
print_speed("9pa[7,^J{akF*@C[/5XoW'aL!><}zA(|PS/%;");
print_speed("|rbG=GTOC]av}-`5yyIts*(jVm0g^p^&0-lzWJVx=yE,+8WWj%tl-@U007X7@FEE7yh9[x_mR%{)Gqt=.3Dh>x");
print_speed("UupuJ&&O^j}(bh!c;%!vUb8Ni-;F([a7WDK*6Gd!<uhj<NJzO0Uh$Fk(BUj8nZ");
print_speed("c'df8NSi<d24Gp}*ldKCBWt*css!w@=Hl;Lqy");
print_speed("t=I9z4>|v1PrS}Wpj9ELYz3e>}#S]l*gWGH=$[UiMMm@]7#rDG}g@s*7");
print_speed("/.M:CESlFFt]+7oE'1<(=");
print_speed("^AR!@GuY6BXFgkO9&l^yPit'^(<!5;REU87%/XJ![^&jjPZ1+DO2{nV2Bh#ngE^d|:oUD4:,u1G#bD@6!]#^Mt[OwE|km'w$QEw3LN05j4c9F");
print_speed("BveD*Sd/$bgQi,Vs)k/{uK>`{@<if@!tt$,i<`HGI");
printf("Score = %llu\n", average_score/n); // The higher the score the slower is the function on average
}

