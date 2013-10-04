#ifndef PARAM_GETTER_H
#define PARAM_GETTER_H

template <class Key, class T> class QMap;
class QString;

class Getter{
public:
    static QMap<QString, QString> get_params();

};

#endif // PARAM_GETTER_H
