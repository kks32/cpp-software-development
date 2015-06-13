#ifndef CLASS_MOP_
#define CLASS_MOP_

class ClassDef {  // typedefs Container, Iterator for attributes
 public:
  ClassDef(ClassDef const* base, const string& name_)
      : baseClass(base), name(name_), definitionFix(false) {
    baseInit();
    effectiveAttributes.insert(effectiveAttributes.end(), ownAttributes.begin(),
                               ownAttributes.end());
  }

  template <typename iterator>
  ClassDef(ClassDef const* base, const string& name_, iterator attribBegin,
           iterator attribEnd)
      : baseClass(base),
        name(name_),
        ownAttributes(attribBegin, attribEnd),
        definitionFix(false) {
    baseInit();
    effectiveAttributes.insert(effectiveAttributes.end(), ownAttributes.begin(),
                               ownAttributes.end());
  }

  string getName() const;
  Object* newObject() const {
    definitionFix = true;
    return new Object(this);
  }

  AttrIterator attribBegin() const;
  AttrIterator attribEnd() const;
  Attribute const& getAttribute(size_t idx) const;
  void addAttribute(const Attribute&);
  size_t getAttributeCount() const;

  size_t findAttribute(string const& name) const {
    // this does a reverse search to find the most derived
    AttributeContainer::const_reverse_iterator i;

    for (i = effectiveAttributes.rbegin(); i != effectiveAttributes.rend();
         ++i) {
      if (i->getName() == name) {
        return distance(i, effectiveAttributes.rend()) - 1;
      }
    }
    return getAttributeCount();
  }

 private:
  void baseInit() {
    if (baseClass) {
      baseClass->definitionFix = true;
      copy(baseClass->attribBegin(), baseClass->attribEnd(),
           back_inserter<AttributeContainer>(effectiveAttributes));
    }
  }

  ClassDef const* const baseClass;
  string name;
  AttributeContainer ownAttributes, effectiveAttributes;
  mutable bool definitionFix;
};

#endif  // Class MOP
