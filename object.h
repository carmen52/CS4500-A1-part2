//lang::CwC

/**
 * Represents a generic object from which all classes derive. Thus, all objects
 * implement the member functions of this class.
 */
class Object {
  public:
      /**
       * Constructs a new Object variable
       */
      Object() {}

      /**
       * Deletes this object and frees the memory it took up.
       */
      virtual ~Object() {}

      /**
       * Returns whether this Object equals the Object pointed to by the given
       * pointer.
       */
      virtual bool equals(Object* other) {}

      /**
       * Returns a hash code value for this Object.
       */
      virtual int hashCode() {}

      /**
       * Returns a const char array representing this Object.
       */
      const char* toString() {}
};
