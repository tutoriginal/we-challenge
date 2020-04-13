/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wav.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 21:43:03 by agossuin          #+#    #+#             */
/*   Updated: 2020/04/12 23:02:39 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "morsec.h"

void		ft_wav_header(int fd)
{
	t_wav	header;

	strncpy(header.riff_tag, "RIFF", 4);
	strncpy(header.wave_tag, "WAVE", 4);
	strncpy(header.fmt_tag, "fmt ", 4);
	strncpy(header.data_tag, "data", 4);
	header.riff_length = 0;
	header.fmt_length = 16;
	header.audio_format = 1;
	header.num_channels = 1;
	header.sample_rate = 44100;
	header.byte_rate = 44100 * 2;
	header.block_align = 1;
	header.bits_per_sample = 16;
	header.data_length = 0;
	write(fd, &header, sizeof(header));
}

void		ft_sound_waves_fd(const char *str, int fd)
{
	char	no_sound[440];
	char	la[44100];
	int		i;

	i = 0;
	while (i < 440)
		no_sound[i++] = 1;
	if (!(i = open("utils/A.wav", O_RDONLY)))
		return ;
	read(i, la, 44100);
	close(i);
	while (*str)
	{
		i = 0;
		if (*str == '-')
			write(fd, la, 24000);
		if (*str == '.')
			write(fd, la, 8000);
		while (*str == '/' && i++ < 100)
			write(fd, no_sound, 220);
		i = 0;
		while (i++ < 50)
			write(fd, no_sound, 220);
		str++;
	}
}

void		ft_wav(const char *str)
{
	int fd;

	if (!(fd = open("morse.wav", O_CREAT | O_WRONLY | O_TRUNC, 0b0110100100)))
		return ;
	ft_wav_header(fd);
	ft_sound_waves_fd(str, fd);
	close(fd);
	write(1, "morse.wav generated\n", 20);
}
