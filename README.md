# schoolbook

При съобщение за грешка напишете clear

Команди

        end - приключва на програмата

        add
                
                student *три имена* - добавя ученик с тези три имена
                
                note *номер на ученик* *име на предмет* *оценка* - добавя оцнка по даден предмет на даден ученик (ако предметът не съществува, ще бъде добавен за ученика)
                
                termnote *номер на ученик* *име на предмет* *оценка* - добавя срочна оценка по даден предмет на даден ученик (ако предметът не съществува, ще бъде добавен за ученика)
                
        erase
                student
                        name
                                first *първо име* - изтрива ученик и цялата информация за него по дадено първо име (ако има повече от един ученик с това име изтрива само един от тях)
                                second *второ име* - изтрива ученик и цялата информация за него по дадено второ име (ако има повече от един ученик с това име изтрива само един от тях)
                                last *фамилия* - изтрива ученик и цялата информация за него по дадена фамилия (ако има повече от един ученик с това име изтрива само един от тях)
                        
                        number *номер на ученик* - изтрива ученик и цялата информация за него по даден номер
                        
                note *номер на ученик* *име на предмет* *оценка* - изтрива оценка по даден предмет на ученик с даден номер
                
                termnote *номер на ученик* *име на предмет* *оценка* - изтрива срочната оценка по даден предмет на ученик с даден номер
                
                subject *номер на ученик* *име на предмет* - изтрива даден предмет и всички оценки по него на ученик с даден номер
                
        find
                number *номер на ученик* - намира ученик с даден номер и отпечатва информацията за него
                
                name
                        first *първо име* - намира всички ученици с дадено първо име и отпечатва информацията за тях
                        
                        second *второ име* - намира всички ученици с дадено второ име и отпечатва информацията за тях
                        
                        last *фамилия* - намира всички ученици с дадена фамилия и отпечатва информацията за тях
                        
        output - отпечатва всички ученици и информацията за тях

        sort
        
                number - соритира учениците по номер и ги отпечатва
                
                name
                
                        first - сортитра учениците по първо име и ги отпечатва
                        
                        second - сортитра учениците по второ име и ги отпечатва
                        
                        last - сортира учениците по фамилия и ги отпечатва
