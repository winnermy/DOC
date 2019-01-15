#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/security.h>

#include "mylsm.h"


/* module name and module index number */
static struct security_lsm mylsm_module = {
	.name = "mylsm",
	.index = LSM_INDEX_UNKNOWN
};


static int mylsm_inode_alloc(struct inode *inode)
{
	return 0;
}

static void mylsm_inode_free(struct inode *inode)
{

}

static int mylsm_inode_init(struct inode *inode, struct inode *dir,
			    const struct qstr *qstr,
			    const char **name, void **value,
			    size_t *len)
{
	return 0;
}


/* mylsm module hooks */
static struct security_hook_list mylsm_hooks[] = {
	LSM_HOOK_INIT(inode_alloc_security, mylsm_inode_alloc),
	LSM_HOOK_INIT(inode_free_security, mylsm_inode_free),
	LSM_HOOK_INIT(inode_init_security, mylsm_inode_init),
	/* other hooks */
};

static __init int mylsm_init(void)
{
	printk(KERN_INFO "MYLSM: Initializing...\n");

	/* compute module index number */
	security_lsm_register(&mylsm_module);

	/* add the module hooks to the hook lists */
	security_add_hooks(mylsm_hooks, ARRAY_SIZE(mylsm_hooks), "mylsm");

	printk(KERN_INFO "MYLSM: Initializing successfully.\n");

	return 0;
}

security_initcall(mylsm_init);
