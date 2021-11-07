married(me,widow).
married(father,daughter).
father_of(father,me).
father_of(father,daughter_son). /*daughter_son é o filho de daughter com o father */
father_of(me,father).
mother_of(daughter,mother).
mother_of(mother,daughter).
mother_of(daughter,daughter_son).
mother_of(widow,my_son). /*my_son é meu filho com a widow */
grandparent_of(me,me).
grandparent_of(me, daughter_son).
grandparent_of(widow,me).

